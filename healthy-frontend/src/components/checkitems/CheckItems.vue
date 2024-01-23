<template>
  <el-button type="primary" style="margin-left: 16px" @click="drawer2 = true" v-if="hideButton">{{props.tcObject.bottonTitle}}</el-button>


 <!-- 选检项目-抽屉 -->
<div id = 'xjxm' class="darwer-box">
  <el-drawer v-model="drawer2" title="I am the title" :with-header="false" >
    <span>{{ tcObject.tableTitle }}</span>
    <el-form :inline="true" :model="formInlineTc" class="demo-form-inline">
    <el-form-item label="关键字:" class="bold-label">
      <!-- 关键字输入框 -->
      <el-input
        v-model="formInlineTc.gjz"
        class="suibian"
        width="50px"
        placeholder="请输入关键字:"
        :suffix-icon="Search"
      />
    </el-form-item>
<!-- 套餐项目-所属科室-下拉菜单 -->
    <el-form-item label="所属科室" class="bold-label">
      <el-select
    v-model="formInlineTc.ssks"
    class="m-2"
    placeholder="请选择"
    size="large"
    style="width: 240px"
  >

    <el-option
      v-for="item in props.tcObject.selectDown "
      :key="item.value"
      :label="item.label"
      :value="item.label"
    />
  </el-select>
</el-form-item>
  <!-- 套餐项目-from表单-按钮 -->
    <el-form-item>
      <el-button type="primary" :icon="Search" @click="handleSearchTc">搜索</el-button>
      <el-button plain @click="handleCzTc">重置</el-button>
    </el-form-item>
  </el-form>

  <!-- 套餐项目-表格数据table -->
  <el-table
    ref="multipleTableRefForTc"
    :data="tcObject.tableDataForTc.slice((currentPage4 - 1) * pageSize4,currentPage4 * pageSize4)"
    style="width: 100%"
    :row-class-name="tableDataFtableRowClassNameForTc"
    @select="selectTc"
    @selection-change="handleSelectionChangeForTc"
  >
    <!-- 单选框 -->
    <el-table-column type = "selection" label="单选框选择" width="180" />
    <el-table-column v-for="item in props.tcObject.tableLieForTc" :key="item" :prop="item.prop" :label="item.label" :width="item.width" :align="item.align" />
  </el-table>
  <el-pagination
      v-model:current-page="currentPage4"
      v-model:page-size="pageSize4"
      :page-sizes="[10, 20, 50, 100]"
      :small="small"
      :disabled="disabled"
      layout="total, sizes, prev, pager, next, jumper"
      :total= props.tcObject.tableDataForTc.length
      @size-change="handleSizeChange"
      @current-change="handleCurrentChange"
    />
  <el-button @click="cancelTc" v-show="showCloseForTc">关闭 </el-button>
  <el-button type="primary" @click="submitTc" v-show = "showSubmitForTc">确定</el-button>
  </el-drawer>
</div>
</template>

<script lang="ts" setup>
import { reactive,ref,defineProps,watch,defineEmits} from 'vue'
import { Search } from '@element-plus/icons-vue'
import { ArrowDown } from '@element-plus/icons-vue'

// 分页属性
const currentPage4 = ref(1)
const pageSize4 = ref(10)
const small = ref(false)
const disabled = ref(false)

//按钮开关
//套餐
const showCloseForTc = ref(true);
const showSubmitForTc = ref(true);


//分页方法-套餐
const handleSizeChange = (val: number) => {
  console.log(`${val} items per page`)
}
const handleCurrentChange = (val: number) => {

}


  // 搜索框的字段存放区域-套餐项目
  const formInlineTc = reactive({
  gjz: '',
  ssks: ''
})




// 套餐项目-表格字段
interface tcxmTableFiled {
  mc: string
  xsj: string
}

//标签设置区域
const value = ref('')
// const drawer = ref(false)
const drawer2 = ref(false)


// 定义抽屉预设
const props = defineProps({
  //包含数据 列 是否显示确定取消按钮
    tcObject:{
      type: Object,
      default: () =>({bottonTitle:'按钮名字',tableTitle:'抽屉表头',
      //是否显示确定取消按钮
      isShowButtonForTc:true,
      //控制触发按钮是否显示
      hideButton:false,
      //控制抽屉是否打开
      openDrawer:false,
      tableLieForTc:[{
        prop:'bind',
        label:'列的显示名称'
      },
      {
        prop:'bind2',
        label:'列的显示名称'
      }],
      tableDataForTc:[{
        bind:'列的显示字段名',
        bind2:'列的显示字段名'
      }],
      selectDown:[{
        value:'字段属性值-绑定用',
        label:'下拉显示的数据'
      }],
    })
    }
})
const hideButton=ref(true)
//初始化方法
created:{
  // console.log("selectDown:" + props.tcObject.selectDown.forEach(prop=>{
  //   console.log("prop:" + prop.value)
  // }))
  // console.log(currentPage4,pageSize4)
  if(!props.tcObject.isShowButtonForTc){
    showSubmitForTc.value = false
    showCloseForTc.value = false
  }
  hideButton.value=props.tcObject.hideButton
  drawer2.value=props.tcObject.openDrawer

}



const emits = defineEmits(['submitTc','cancelTc','rowDataForTcMd'])

//套餐抽屉的打开与关闭
const openTc = () => drawer2.value = true
const closeTc = () => drawer2.value = false




const multipleTableRefForTc =  ref()
const multipleSelectionForTc = ref([])
const rowDataForTc = ref([]);

// 套餐抽屉的确认与取消按钮
const submitTc = () => {
  //获取当前选中行的数据
  emits('submitTc',rowDataForTc.value);
  cancelTc()
}
const cancelTc = () => {
  // 清除 所有勾选项
  multipleTableRefForTc.value.clearSelection()
  closeTc()
}


const rowDataForTcMd = () => {
  emits('rowDataForTcMd',rowDataForTc.value);
}

// const rowDataForCyMd = () => {
//   emits('rowDataForCyMd',rowDataForTc.value);
// }
let loading = ref(false)

const showloading = () => loading.value = true
const hideloading = () => loading.value = false

// 暴露出去
defineExpose({
  openTc, closeTc, cancelTc,submitTc, showloading, hideloading,rowDataForTcMd
})

// 点击事件区域


//处理搜索-套餐项目
const handleSearchTc = () => {
  console.log(formInlineTc.gjz)
  console.log(formInlineTc.ssks)
}

//处理重置-套餐项目
const handleCzTc = () => {
  console.log('Cz')
   // 将表单中的输入框清空
   for (const key in formInlineTc) {
    formInlineTc[key] = ''
  }
}





//搜索变化
const handleSelectionChangeForTc = (val) => {
  multipleSelectionForTc.value = val
  rowDataForTc.value =val
}





// 套餐项目-表格绑定事件selectTc
const selectTc = (selection, row) => {
  // 清除 所有勾选项
  multipleTableRefForTc.value.clearSelection()
  // 当表格数据都没有被勾选的时候 就返回
  // 主要用于将当前勾选的表格状态清除
  if (selection.length == 0) return
  multipleTableRefForTc.value.toggleRowSelection(row, true)
  // rowData.value = row
}





//套餐项目-表格的class样式
const tableDataFtableRowClassNameForTc = ({
  row,
  rowIndex,
}: {
  row: tcxmTableFiled
  rowIndex: number
}) => {
  if (rowIndex === 1) {
    return 'warning-row'
  } else if (rowIndex === 3) {
    return 'success-row'
  }
  return ''
}


</script>

<style lang="scss" scoped>
.el-table .warning-row {
  --el-table-tr-bg-color: var(--el-color-warning-light-9);
}
.el-table .success-row {
  --el-table-tr-bg-color: var(--el-color-success-light-9);
}
.suibian{
  display: flex;
      justify-content: space-between;
      align-items: center;
}
</style>
