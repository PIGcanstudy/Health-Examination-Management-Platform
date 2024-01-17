<template>
  <el-button type="primary" style="margin-left: 16px" @click="drawer = true">套餐类型</el-button>
  <el-button type="primary" style="margin-left: 16px" @click="drawer2 = true">选检项目</el-button>

  <!-- 套餐类型抽屉 -->
  <el-drawer v-model="drawer" title="I am the title" :with-header="false">
    <span>从业套餐选择</span>
    <el-form :inline="true" :model="formInline" class="demo-form-inline">
    <el-form-item label="关键字" class="bold-label">
          <!-- 从业套餐选择-关键字输入框 -->
      <el-input
        v-model="formInline.gjz"
        class="suibian"
        width="50px"
        placeholder="请输入关键字"
        :suffix-icon="Search"
      />
    </el-form-item>

    <!-- from表单按钮 -->
    <el-form-item>
      <el-button type="primary" :icon="Search" @click="handleSearch">搜索</el-button>
      <el-button plain @click="handleCz">重置</el-button>
    </el-form-item>
  </el-form>

  <!-- 从业套餐选择-表格数据部分 -->
  <el-table
    ref="multipleTableRef"
    :data="tableData"
    style="width: 100%"
    :row-class-name="tableRowClassNameForCy"
    @select="select"
    @selection-change="handleSelectionChangeForCy"
  > 
    <el-table-column  type="selection" label="选择" width="180" />
    <el-table-column prop="tcmc" label="套餐名称" width="180" />
    <el-table-column prop="tcjp" label="套餐简拼" />
  </el-table>
  </el-drawer>

    <!-- 选检项目-抽屉 -->
  <el-drawer v-model="drawer2" title="I am the title" :with-header="false">
    <span>套餐项目</span>
    <el-form :inline="true" :model="formInline" class="demo-form-inline">
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
      v-for="item in options"
      :key="item.value"
      :label="item.label"
      :value="item.value"
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
    :data="tableDataForTc"
    style="width: 100%"
    :row-class-name="tableDataFtableRowClassNameForTc"
    @select="selectTc"
    @selection-change="handleSelectionChangeForTc"
  >
    <!-- 单选框 -->
    <el-table-column type = "selection" label="XZ" width="180" />
    <el-table-column prop="mc" label="名称" width="180" />
    <el-table-column prop="xsj" label="销售价(元)" />
  </el-table>
  </el-drawer>
</template>

<script lang="ts" setup>
import { ref } from 'vue'
import { Calendar, Search } from '@element-plus/icons-vue'
import { ArrowDown } from '@element-plus/icons-vue'



// 下拉菜单存放数据区域
const options = [
  {
    value: 'Option',
    label: '蔡徐坤',
    value1: 'Option1',
    label1: '蔡徐坤1',
    value2: 'Option2',
    label2: '蔡徐坤2',
    value3: 'Option3',
    label3: '蔡徐坤3',
  }]

   // 搜索框的字段存放区域-从业套餐
   const formInline = ref({
  gjz: '',
})

  // 搜索框的字段存放区域-套餐项目
  const formInlineTc = ref({
  gjz: '',
  ssks: ''
})

//从业套餐-表格字段
interface cytcTableFiled {
  tcmc: string
  tcjp: string
}

// 套餐项目-表格字段
interface tcxmTableFiled {
  mc: string
  xsj: string
}

//标签设置区域
const value = ref('')
const drawer = ref(false)
const drawer2 = ref(false)


// 点击事件区域

//处理搜索-从业套餐
const handleSearch = () => {
  alert('search')
}

//处理重置-从业套餐
const handleCz = () => {
  console.log('Cz')
   // 将表单中的输入框清空
   for (const key in formInline) {
    formInline[key] = ''
  }
}

//处理搜索-套餐项目
const handleSearchTc = () => {
  alert('search')
}

//处理重置-套餐项目
const handleCzTc = () => {
  console.log('Cz')
   // 将表单中的输入框清空
   for (const key in formInlineTc) {
    formInlineTc[key] = ''
  }
}

const multipleTableRef =  ref()
const multipleSelectionForCy = ref([])
const multipleSelectionForTc = ref([])

const handleSelectionChangeForCy = (val) => {
  console.log("从业套餐selectChangge: " + val);
  multipleSelectionForCy.value = val
}

const handleSelectionChangeForTc = (val) => {
  multipleSelectionForTc.value = val
}

// 从业套餐选择-表格绑定事件select
const select = (selection, row) => {
  console.log("从业套餐select: " + selection)
  console.log("从业套餐select: " + row)
  // 清除 所有勾选项
  multipleTableRef.value.clearSelection()
  // 当表格数据都没有被勾选的时候 就返回
  // 主要用于将当前勾选的表格状态清除
  if (selection.length == 0) return
  multipleTableRef.value.toggleRowSelection(row, true)
}


const multipleTableRefForTc =  ref()

// 套餐项目-表格绑定事件selectTc
const selectTc = (selection, row) => {
  // 清除 所有勾选项
  multipleTableRefForTc.value.clearSelection()
  // 当表格数据都没有被勾选的时候 就返回
  // 主要用于将当前勾选的表格状态清除
  if (selection.length == 0) return
  multipleTableRefForTc.value.toggleRowSelection(row, true)
}



//从业套餐-表格的class样式
const tableRowClassNameForCy = ({
  row,
  rowIndex,
}: {
  row: cytcTableFiled
  rowIndex: number
}) => {
  if (rowIndex === 1) {
    return 'warning-row'
  } else if (rowIndex === 3) {
    return 'success-row'
  }
  return ''
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

//从业套餐-表格数据
const tableData: cytcTableFiled[] = [
  {
    tcmc: '优惠套餐1',
    tcjp: 'YHTC',
  },
  {
    tcmc: '健康套餐1',
    tcjp: 'CYTJ',
  },
  {
    tcmc: '优惠套餐2',
    tcjp: 'JC3',
  },
  {
    tcmc: '健康套餐2',
    tcjp: 'JC4',
  },
]

//套餐项目-表格数据
const tableDataForTc: tcxmTableFiled[] = [
  {
    mc: '项目1',
    xsj: '10',
  },
  {
    mc: '项目2',
    xsj: '20',
  },
  {
    mc: '项目3',
    xsj: '30',
  },
  {
    
    mc: '项目4',
    xsj: '40',
  },
]
</script>

<style>
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