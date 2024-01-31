<!-- 类型库 -->
<template>
    <div>
      <el-form :inline="true" :model="formInlineLxk" class="demo-form-inline">
    <el-form-item label="类型名称:" class="bold-label">
      <!-- 关键字输入框 -->
      <el-input
        v-model="formInlineLxk.lxmc"
        class="suibian"
        width="50px"
        placeholder="请输入"
        :suffix-icon="Search"
      />
    </el-form-item>
<!-- 套餐项目-所属科室-下拉菜单 -->
<el-form-item label="类型编码" class="bold-label">
      <!-- 关键字输入框 -->
      <el-input
        v-model="formInlineLxk.lxbm"
        class="suibian"
        width="50px"
        placeholder="请输入"
        :suffix-icon="Search"
      />
</el-form-item>
  <!-- 套餐项目-from表单-按钮 -->
    <el-form-item>
      <el-button type="primary" :icon="Search" @click="handleSearchLxk">搜索</el-button>
      <el-button plain @click="handleCzLxk">重置</el-button>
      <div >
      <NewButtonHx :sylxsw="sylxsw" />
    </div>
    </el-form-item>
  </el-form>

    <el-button type="primary" style="margin-right: 10px" @click="dialogFormVisible = true">
      <el-icon style="margin-right: 5px"><Plus /></el-icon>
      新增
    </el-button>

    <el-select placeholder="更多操作" style="width: 100px" v-if="!isOnlyShowButton">
      <el-option @click="dialogFormVisible = true">
        <el-icon style="margin-right: 5px"><icon-refresh /></el-icon>
        刷新
      </el-option>
      <el-option @click="dialogFormVisible = true">
        <el-icon style="margin-right: 5px"><icon-bottom /></el-icon>
        导出本页数据
      </el-option>
    </el-select>

     <!-- 对话框 -->
     <el-dialog v-model="dialogFormVisible" title="新增" width="1025px">

      <!-- 表单 -->
      <el-form :label-position="right" :inline="true" :model="formInline" class="demo-form-inline">
        <el-col :span="24">
        <el-form-item  label="类型名称" class="bold-label">
          <el-input v-model="formInline.lxmc" placeholder="请输入类型名称" />
</el-form-item>
</el-col>
<el-form-item  label="类型编码" class="bold-label">
  <el-input v-model="formInline.lxbm" placeholder="请输入类型编码" />
</el-form-item>
<el-form-item  label="上级类型" class="bold-label">
      <el-select v-model="formInline.sjlx" class="m-2" placeholder="请选择" size="large" style="width: 240px">
    <el-option v-for="item in sjlxsw " :key="item" :label="item.label" :value="item.value"/>
  </el-select>
</el-form-item>
  <el-form-item label="排序" default="0">
      <el-input v-model="formInline.px" />
</el-form-item>
  <el-form-item label="备注">
      <el-input v-model="formInline.bz" type="textarea" placeholder="请输入备注"/>
  </el-form-item>
</el-form>

      <!-- 底栏 -->
      <template #footer>
        <span class="dialog-footer">
          <el-button
            @click="dialogFormVisible = false;resetFrom()"
            >取消</el-button
          >
          <el-button
            type="primary"
            @click="onSubmit();resetFrom()"
          >
            提交
          </el-button>
        </span>
      </template>
    </el-dialog>
    </div>
  
 <!-- 类型库-表格数据table -->
 <el-table
    ref="multipleTableRefForLxk"
    :data="tableDataForLxk.slice((currentPage4 - 1) * pageSize4,currentPage4 * pageSize4)"
    style="width: 100%"
    :row-class-name="tableRowClassName"
    @select="selectTc"
    @selection-change="handleSelectionChangeForTc"
  >
    <!-- 单选框 -->
    <el-table-column type = "selection" label="单选框选择" width="180" />
    <el-table-column v-for="lieColumn in tableLieForLxk" :key="lieColumn" :prop="lieColumn.prop" :label="lieColumn.label"  />
    <el-table-column prop="cz" label="操作" v-if="EditDButtonShow">
      <template #default="scope" >
        <el-button size="small" @click="handleEdit(scope.$index, scope.row)"
          >编辑</el-button
        >
        <el-button
          size="small"
          type="danger"
          @click="handleDelete(scope.$index, scope.row)"
          >删除</el-button
        >
      </template>
    </el-table-column>
  </el-table>
  <el-pagination
      v-model:current-page="currentPage4"
      v-model:page-size="pageSize4"
      :page-sizes="[10, 20, 50, 100]"
      :small="small"
      :disabled="disabled"
      layout="total, sizes, prev, pager, next, jumper"
      :total= tableDataForLxk.length
      @size-change="handleSizeChange"
      @current-change="handleCurrentChange"
    />
</template>

<script lang="ts" setup>
import { reactive,ref,defineProps} from 'vue'
import { Search } from '@element-plus/icons-vue'
import { ElMessage, ElMessageBox } from 'element-plus'
import NewButtonHx from  '@/components/checkitems/NewButtonHx.vue'

//搜索框的变量
  // 搜索框的字段存放区域-类型库
  const formInlineLxk = reactive({
  lxmc: '',
  lxbm: ''
})
//处理搜索-类型库
const handleSearchLxk = () => {
  console.log(formInlineLxk.lxmc)
  console.log(formInlineLxk.lxbm)
}

//处理重置-类型库
const handleCzLxk = () => {
  console.log('Cz')
   // 将表单中的输入框清空
   for (const key in formInlineLxk) {
    formInlineLxk[key] = ''
  }
}
//NewButtonHX的变量
const dialogFormVisible = ref(false)
// 对话框数据字段
const formInline = reactive({
  lxmc: '',
  lxbm: '',
  sjlx:'',
  px:'',
  bz:''
})

const props = defineProps({
  sjlxsw: {
    type: Array,
    default: () => []
  },
  isOnlyShowButton: {
    type: Boolean,
    default: false
  }
})

//新增按钮下拉框的数据
const sjlxsw = [{
        value:'字段属性值-绑定用',
        label:'下拉显示的数据'
      }]


// 提交表单
const onSubmit = () => {
  
}

// 清空表单
const resetFrom = () => {
 // 将表单中的输入框清空
 for (const key in formInline) {
  formInline[key] = ''
  }
}
//表格table相关
const currentPage4 = ref(1)
const pageSize4 = ref(10)
const small = ref(false)
const disabled = ref(false)
const multipleTableRefForLxk = ref()

const EditDButtonShow = ref(true)
const hideButton=ref(false)
//是否显示下拉框
const isShowSelectDown=ref(true)
const title = ref()

//搜索变化
const handleSelectionChangeForTc = (val) => {
  multipleSelectionForTc.value = val
  rowDataForTc.value =val
}

// 套餐项目-表格绑定事件selectTc
const selectTc = (selection, row) => {
  // 清除 所有勾选项
  multipleTableRefForLxk.value.clearSelection()
  // 当表格数据都没有被勾选的时候 就返回
  // 主要用于将当前勾选的表格状态清除
  if (selection.length == 0) return
  multipleTableRefForLxk.value.toggleRowSelection(row, true)

}



//套餐项目-表格的class样式
const tableRowClassName = ({
  row,
  rowIndex,
}: {
  row: Array<String>
  rowIndex: number
}) => {
  if (rowIndex % 2 === 0) {
    return 'warning-row'
  } else if (rowIndex % 2  === 1) {
    return 'success-row'
  }
  return ''
}

//分页方法-套餐
const handleSizeChange = (val: number) => {
  console.log(`${val} items per page`)
}
const handleCurrentChange = (val: number) => {

}

//编辑
const handleEdit = (index: number, row: Array<String>) => {
  alert(index)
  alert(row)
}

//删除
const handleDelete = (index: number, row: Array<String>) => {
  ElMessageBox.confirm(
    'proxy will permanently delete the data. Continue?',
    'Warning',
    {
      confirmButtonText: 'OK',
      cancelButtonText: 'Cancel',
      type: 'warning',
    }
  )
    .then(() => {
      //发请求给后端
      ElMessage({
        type: 'success',
        message: 'Delete completed',
      })
    })
    .catch(() => {
      ElMessage({
        type: 'info',
        message: 'Delete canceled',
      })
    })
  alert(index)
  alert(row)
}

//套餐项目表格列
const tableLieForLxk = [
  {
    prop: 'lxmc',
    label: '类型名称'
  },
  {
    prop: 'lxbm',
    label: '类型编码'
  },
  {
    prop: 'px',
    label: '排序'
  },
  {
    prop: 'bz',
    label: '备注'
  }
]
 //套餐项目表格数据
 const tableDataForLxk = [
  {
    lxmc: '经济类型',
    lxbm: 'TYPE_002',
    px: '2',
    bz: ''
  },{
    lxmc: '职业危害因素',
    lxbm: 'TYPE_001',
    px: '1',
    bz: ''
  },{
    lxmc: '行业类别',
    lxbm: 'TYPE_003',
    px: '3',
    bz: ''
  }
]


const formData = reactive({
  lxmc: '',
  lxbm: '',
  px: '',
  bz: ''
})
</script>

<style lang="scss">
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
