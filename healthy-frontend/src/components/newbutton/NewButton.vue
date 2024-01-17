<template>
  <div>
    <el-button @click="showDrawer">新增</el-button>

    <el-drawer :model-value="drawerVisible" title="新增" class="custom-drawer">
      <el-form :model="formData" label-position="right">
        <div class="form-row">
          <el-form-item label="单位名称">
            <el-input v-model="formData.unitName"></el-input>
          </el-form-item>
          <el-form-item label="体检类型">
            <el-select v-model="formData.checkupType" placeholder="请选择">
              <el-option label="类型1" value="type1"></el-option>
              <el-option label="类型2" value="type2"></el-option>
              <!-- 其他选项... -->
            </el-select>
          </el-form-item>
        </div>
        <!-- 其他输入框和下拉框... -->
      </el-form>

      <div class="form-row">
          <el-form-item label="统一社会信用代码">
            <el-input v-model="formData.unitName"></el-input>
          </el-form-item>
          <el-form-item label="行业类型">
            <el-select v-model="formData.checkupType" placeholder="请选择">
              <el-option label="类型1" value="type1"></el-option>
              <el-option label="类型2" value="type2"></el-option>
              <!-- 其他选项... -->
            </el-select>
          </el-form-item>
        </div>
        <div class="form-row">
          <el-form-item label="所属地区">
            <el-select v-model="formData.checkupType" placeholder="请选择">
              <el-option label="类型1" value="type1"></el-option>
              <el-option label="类型2" value="type2"></el-option>
              <!-- 其他选项... -->
            </el-select>
          </el-form-item>
          <el-form-item label="经济类型">
            <el-select v-model="formData.checkupType" placeholder="请选择">
              <el-option label="类型1" value="type1"></el-option>
              <el-option label="类型2" value="type2"></el-option>
              <!-- 其他选项... -->
            </el-select>
          </el-form-item>
        </div>
        <div class="form-row">
          <el-form-item label="单位注册地址">
            <el-input v-model="formData.unitName"></el-input>
          </el-form-item>
          <el-form-item label="企业规模">
            <el-select v-model="formData.checkupType" placeholder="请选择">
              <el-option label="类型1" value="type1"></el-option>
              <el-option label="类型2" value="type2"></el-option>
              <!-- 其他选项... -->
            </el-select>
          </el-form-item>
        </div>
        <div class="form-row">
          <el-form-item label="体检联系人姓名">
            <el-input v-model="formData.unitName"></el-input>
          </el-form-item>
          <el-form-item label="体检联系人电话">
            <el-input v-model="formData.unitName"></el-input>
          </el-form-item>
        </div>

      <div class="drawer-footer">
        <el-button @click="closeDrawer">取消</el-button>
        <el-button type="primary" @click="saveData">保存</el-button>
      </div>
    </el-drawer>
  </div>
</template>

<script setup>
import { ref } from 'vue';

const drawerVisible = ref(false);

const formData = {
  unitName: '',
  checkupType: '',
  // 其他字段...
};

const showDrawer = () => {
  drawerVisible.value = true;
};

const closeDrawer = () => {
  drawerVisible.value = false;
};

const saveData = () => {
  // 处理保存逻辑，根据实际需求进行调整
  console.log('Saving data:', formData);
  closeDrawer();
};
</script>

<style scoped>
.custom-drawer {
  width: 2000px; /* 调整为你需要的宽度 */
}

.form-row {
  display: flex;
  justify-content: space-between;
}
</style>
